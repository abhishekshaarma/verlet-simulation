#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "particle.h"

class Quadtree {
public:
    Quadtree(sf::FloatRect boundary, int capacity)
        : boundary(boundary), capacity(capacity), divided(false)
    {}

    bool insert(Particle* particle)
    {
        if (!boundary.contains(particle->position))
        {
            return false;
        }

        if (particles.size() < capacity)
        {
            particles.push_back(particle);
            return true;
        }

        if (!divided)
        {
            subdivide();
        }

        if (northeast->insert(particle)) return true;
        if (northwest->insert(particle)) return true;
        if (southeast->insert(particle)) return true;
        if (southwest->insert(particle)) return true;

        return false;
    }

    std::vector<Particle*> query(sf::FloatRect range) {
        std::vector<Particle*> found;
        if (!boundary.intersects(range))
        {
            return found;
        }

        for (auto& particle : particles)
        {
            if (range.contains(particle->position)) {
                found.push_back(particle);
            }
        }

        if (divided)
        {
            auto ne = northeast->query(range);
            found.insert(found.end(), ne.begin(), ne.end());

            auto nw = northwest->query(range);
            found.insert(found.end(), nw.begin(), nw.end());

            auto se = southeast->query(range);
            found.insert(found.end(), se.begin(), se.end());

            auto sw = southwest->query(range);
            found.insert(found.end(), sw.begin(), sw.end());
        }

        return found;
    }

private:
    void subdivide() {
        float x = boundary.left;
        float y = boundary.top;
        float w = boundary.width / 2;
        float h = boundary.height / 2;

        northeast = std::make_unique<Quadtree>(sf::FloatRect(x + w, y, w, h), capacity);
        northwest = std::make_unique<Quadtree>(sf::FloatRect(x, y, w, h), capacity);
        southeast = std::make_unique<Quadtree>(sf::FloatRect(x + w, y + h, w, h), capacity);
        southwest = std::make_unique<Quadtree>(sf::FloatRect(x, y + h, w, h), capacity);

        divided = true;
    }

    sf::FloatRect boundary;
    int capacity;
    bool divided;
    std::vector<Particle*> particles;
    std::unique_ptr<Quadtree> northeast;
    std::unique_ptr<Quadtree> northwest;
    std::unique_ptr<Quadtree> southeast;
    std::unique_ptr<Quadtree> southwest;
};

#endif // QUADTREE_H
