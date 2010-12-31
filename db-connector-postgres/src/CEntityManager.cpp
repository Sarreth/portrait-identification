#include "CEntityManager.hpp"

CEntityManager *CEntityManager::instance = NULL;

CEntityManager *CEntityManager::getInstance() {
    if (CEntityManager::instance == NULL) {
        CEntityManager::instance = new CEntityManager();
    }
    return CEntityManager::instance;
}

CEntityManager::CEntityManager() {
    this->connect("localhost", "identification", "user", "user");
}

void CEntityManager::connect(std::string host, std::string database,
        std::string user, std::string password) {
    if (host.empty() || database.empty() || user.empty() || password.empty()) {
        throw "Connection to database failed: Connection not configured";
    }
    std::string connection_string = "";
    connection_string
            .append("dbname = ").append(database)
            .append(" host = ").append(host)
            .append(" user = ").append(user)
            .append(" password = ").append(password);

    this->conn = PQconnectdb(connection_string.c_str());

    if (PQstatus(this->conn) != CONNECTION_OK) {
        //fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(this->conn);
        std::string error = "Connection to database failed: ";
        throw error.append(PQerrorMessage(this->conn));
    }
}

void CEntityManager::persist(CEntity *entity) {
    puts("start insert");
    std::string query = "insert into ";
    query.append(entity->getTableName());

    std::string names = "(";
    std::string values = ")values(";

    if (entity->getId() != 0) {
        names.append("\"").append(entity->getIdName()).append("\"");
        values.append("\'").append(entity->getIdName()).append("\'");
    }

    const m_values *map = entity->getRow();
    for (m_values::const_iterator i = map->begin(); i != map->end(); i++) {
        names.append("\"").append(i->first).append("\",");
        values.append("\'").append(i->second).append("\',");
    }
    query.append(names.replace(names.end() - 1, names.end(),
            values.replace(values.end() - 1, values.end(), ") RETURNING \"")))
            .append(entity->getIdName()).append("\";");

    PGresult *res = PQexec(conn, query.c_str());
    puts("finish insert");
    printf("result is: %d\n", PQresultStatus(res));
    switch (PQresultStatus(res)) {
        case PGRES_TUPLES_OK:
            entity->setId(atoi(PQgetvalue(res, 0, 0)));
            puts("ok insert");
            break;
        default:
            std::string message = "Error when inserting";
            puts(message.append(PQresultErrorMessage(res)).c_str());
            break;
    }
    PQclear(res);
    puts("exit insert");
}

void CEntityManager::merge(CEntity *entity) {
    if (entity->getId() == 0) {
        this->persist(entity);
        return;
    }

    std::string query = "update ";
    query.append(entity->getTableName()).append(" set ");

    const m_values *map = entity->getRow();
    for (m_values::const_iterator i = map->begin(); i != map->end(); i++) {
        query.append("\"").append(i->first).append("\"=\'")
                .append(i->second).append("\',");
    }

    std::stringstream ss;
    ss << entity->getId();
    query.replace(query.end() - 1, query.end(), " where \"")
            .append(entity->getIdName()).append("\"=\'")
            .append(ss.str()).append("\';");

    PGresult *res = PQexec(conn, query.c_str());
    switch (PQresultStatus(res)) {
        case PGRES_COMMAND_OK:
            break;
        default:
            std::string message = "Error when inserting";
            puts(message.append(PQresultErrorMessage(res)).c_str());
            break;
    }
    PQclear(res);
}

void CEntityManager::remove(CEntity *entity) {
    if (entity->getId() == 0) {
        throw "ID could not be empty";
    }

    std::stringstream ss;
    ss << entity->getId();
    std::string query = "delete from ";
    query.append(entity->getTableName()).append(" where \"")
            .append(entity->getIdName()).append("\"=\'")
            .append(ss.str()).append("\';");

    PGresult *res = PQexec(conn, query.c_str());
    std::string message = "";
    switch (PQresultStatus(res)) {
        case PGRES_COMMAND_OK:
            ss.str("");
            ss << entity->getId();
            puts(message.append("Deleting ok, id = ").append(ss.str()).c_str());
            break;
        default:
            ss.str("");
            ss << entity->getId();
            puts(message.append("Error when removing, id = ")
                    .append(ss.str()).append(" Cause: ")
                    .append(PQresultErrorMessage(res)).c_str());
            break;
    }
    PQclear(res);
}

std::list<CEntity *> CEntityManager::find(CEntity *entity) {

}
