#ifndef _TRACKER_H_5G2Y7UTS
#define _TRACKER_H_5G2Y7UTS

#include "Node.h"
#include "Animation.h"

/*
 *  A specific type of Node that changes behavior based on another node.
 *
 *  For things like turrets and cameras that need to either latch onto or face
 *  a target as it moves.
 *
 *  TODO: Should figure out a way to make this optimized, maybe a node cache
 *  callback for trackers that need to know world matrix
 */
class Tracker:
    public Node
{
    public:
        Tracker() = default;
        Tracker(const std::shared_ptr<Node>& target):
            m_pTarget(target)
        {
            update_tracking();
        }
        virtual ~Tracker() {}

        void track(
            const std::shared_ptr<Node>& target = std::shared_ptr<Node>()
        ){
            m_pTarget = target;
            update_tracking();
        }

        virtual void logic_self(Freq::Time t);

        enum class Mode: uint32_t {
            FOLLOW, // move with target, but don't copy orientation
            STICK, // stick to target, copying orientation and position
            ORIENT
        };

        void focal_offset(const glm::vec3& v) {
            m_FocalOffset = v;
        }

        void focus_time(Freq::Time t) {
            m_FocusTime = t;
        }

    private:

        void update_tracking();

        //Freq::Time m_tDelay;
        std::weak_ptr<Node> m_pTarget;
        Animation<glm::mat4> m_Animation;
        glm::vec3 m_FocalOffset;
        Freq::Time m_FocusTime = Freq::Time(200);

        /*
         * The offset to reapply after the focus has set matrix
         * Can be translation or orientation change
         */
        glm::mat4 m_Offset;
};

#endif
