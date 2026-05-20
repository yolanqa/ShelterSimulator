#pragma once

#include <exception>
#include <string>

class AdapostException : public std::exception {
protected:
    std::string mesaj;
public:
    explicit AdapostException(const std::string& mesaj) : mesaj(mesaj) {}
    const char* what() const noexcept override { return mesaj.c_str(); }
};


class RasaInvalidaPisicaException : public AdapostException {
public:
    explicit RasaInvalidaPisicaException(const std::string& rasa): AdapostException("Rasa invalida pentru pisica: " + rasa) {}
};


class ApaInvalidaException : public AdapostException {
public:
    explicit ApaInvalidaException(const std::string& apa): AdapostException("Tip apa invalid: " + apa) {}
};

class CuloareInvalidaException : public AdapostException {
public:

    explicit CuloareInvalidaException(const std::string& culoare): AdapostException("Culoare invalida: " + culoare) {}

};


class CapacitatePadocException : public AdapostException {
public:
    explicit CapacitatePadocException()
        : AdapostException("Padocul este plin!") {}
};

class BugetInsuficientException : public AdapostException {
public:
    explicit BugetInsuficientException()
        : AdapostException("Buget insuficient!") {}
};

class RasaInvalidaException : public AdapostException {
public:
    explicit RasaInvalidaException(const std::string& rasa)
        : AdapostException("Rasa invalida: " + rasa) {}
};