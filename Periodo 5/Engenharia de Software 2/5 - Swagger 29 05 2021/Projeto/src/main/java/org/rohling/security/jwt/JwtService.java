package org.rohling.security.jwt;

import io.jsonwebtoken.Claims;
import io.jsonwebtoken.ExpiredJwtException;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.SignatureAlgorithm;
import org.rohling.domain.entity.User_;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.Date;
import java.util.HashMap;

@Service
public class JwtService {

    @Value("${security.jwt.expiration}")
    private String expiration;

    @Value("${security.jwt.key}")
    private String key;


    private Claims getClaims(String token) throws ExpiredJwtException {
        return  Jwts.parser()
                .setSigningKey(key)
                .parseClaimsJws(token)
                .getBody();
    }

    public boolean isValid(String token) {
        try {
            Claims claims = getClaims(token);
            LocalDateTime date =  claims.getExpiration().toInstant().atZone(ZoneId.systemDefault()).toLocalDateTime();
            return !LocalDateTime.now().isAfter(date);
        } catch (Exception e) {
            return false;
        }
    }

    public String getUserLogin(String token) throws ExpiredJwtException {
        return (String) getClaims(token).getSubject();
    }

    public String generateToken(User_ user) {
        long expirationTime = Long.parseLong(expiration);
        LocalDateTime expirationDate = LocalDateTime.now().plusMinutes(expirationTime);
        Date date = Date.from(expirationDate.atZone(ZoneId.systemDefault()).toInstant());

        HashMap<String, Object> claims = new HashMap<>();
        claims.put("mail", "user@user.com");
        claims.put("roles", "USER");

        return  Jwts.builder()
                .setSubject(user.getLogin())
                .setExpiration(date)
                .setClaims(claims)
                .signWith(SignatureAlgorithm.HS512, key)
                .compact();
    }
}
