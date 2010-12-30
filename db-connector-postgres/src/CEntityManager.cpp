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
    std::string table_name = entity->getTableName();
    std::string query = "insert into ";
    query.append(table_name);

    const m_values *map = entity->getRow();

    std::string names = "(";
    std::string values = ")values(";

    if (entity->getId() != 0) {
        names.append("\"").append(entity->getPkName()).append("\"");
        values.append("\'").append(entity->getPkName()).append("\'");
    }

    for (m_values::const_iterator i = map->begin(); i != map->end(); i++) {
        names.append("\"").append(i->first).append("\",");
        values.append("\'").append(i->second).append("\',");
    }
    query.append(names.replace(names.end() - 1, names.end(),
            values.replace(values.end() - 1, values.end(), ");")));
    PGresult *res = PQexec(conn, query.c_str());
    puts(query.c_str());
}

void CEntityManager::merge() {

}

void CEntityManager::remove() {

}

void CEntityManager::find() {

}
