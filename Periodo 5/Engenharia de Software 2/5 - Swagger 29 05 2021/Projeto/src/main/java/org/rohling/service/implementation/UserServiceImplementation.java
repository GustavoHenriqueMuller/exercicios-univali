package org.rohling.service.implementation;

import org.rohling.domain.entity.User_;
import org.rohling.domain.repository.UserRepository;
import org.rohling.exception.InvalidPasswordException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
public class UserServiceImplementation implements UserDetailsService {

    @Autowired
    private PasswordEncoder passwordEncoder;

    @Autowired
    private UserRepository userRepository;

    public UserDetails authenticate(User_ user) {
        UserDetails userDetails = loadUserByUsername(user.getLogin());
        boolean matches = passwordEncoder.matches(user.getPassword(), userDetails.getPassword());

        if(matches) {
            return userDetails;
        }
        throw new InvalidPasswordException();
    }

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        User_ user =  userRepository.findByLogin(username).orElseThrow(() -> new UsernameNotFoundException("User not found"));

        String[] roles = user.isAdmin() ? new String[]{"ADMIN", "USER"} : new String[]{"USER"};

        return User.builder()
                .username(user.getLogin())
                .password(user.getPassword())
                .roles(roles)
                .build();
    }

    @Transactional
    public User_ save(User_ user) {
        userRepository.save(user);
        return user;
    }
}
