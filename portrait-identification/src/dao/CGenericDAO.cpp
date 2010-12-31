#include "dao/CGenericDAO.hpp"

CGenericDAO::CGenericDAO(CEntityManager* em) {
    this->em = em;
}

CGenericDAO::~CGenericDAO() {
}

CEntity *CGenericDAO::getById(int id) {

}

std::list<CEntity *> CGenericDAO::getAll() {

}

void CGenericDAO::save(CEntity *entity) {
    if (entity->getId() == 0) {
        em->persist(entity);
        return;
    }
    em->merge(entity);
}

void CGenericDAO::remove(CEntity *entity) {
    if (entity->getId() == 0) {
        throw "Id could not be empty";
    }
    em->remove(entity);
}
