#ifndef RESERVOIR_HPP
#define RESERVOIR_HPP

class Reservoir {
public:
    virtual ~Reservoir() = default;
    virtual bool checkVolume(float amount) const = 0;
    virtual void use(float amount) = 0;
    virtual void refill(float amount) = 0;
    virtual float getVolume() const = 0;
};

#endif 
