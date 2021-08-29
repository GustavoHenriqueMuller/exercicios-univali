package org.rohling.domain.repository;

import org.rohling.domain.entity.User_;
import org.springframework.data.jpa.repository.JpaRepository;

import javax.swing.text.html.Option;
import java.util.Optional;

public interface UserRepository extends JpaRepository<User_, Integer> {
    Optional<User_> findByLogin(String login);

}
