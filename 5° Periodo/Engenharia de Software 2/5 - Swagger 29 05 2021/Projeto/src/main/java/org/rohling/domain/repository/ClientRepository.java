package org.rohling.domain.repository;

import org.rohling.domain.entity.Client;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;

public interface ClientRepository extends JpaRepository<Client, Integer> {
    @Query("SELECT c FROM Client c LEFT JOIN FETCH c.orders o WHERE c.id = :id")
    Client findClientByIdFetchOrders(@Param("id") Integer id);
}
