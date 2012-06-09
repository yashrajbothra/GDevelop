/**

Game Develop - Timed Event Extension
Copyright (c) 2011-2012 Florian Rival (Florian.Rival@gmail.com)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
    claim that you wrote the original software. If you use this software
    in a product, an acknowledgment in the product documentation would be
    appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

    3. This notice may not be removed or altered from any source
    distribution.

*/

#if defined(GD_IDE_ONLY)

#ifndef TIMEDEVENT_H
#define TIMEDEVENT_H
#include "GDCore/Events/Event.h"
#include <map>
#include "GDL/ManualTimer.h"
class RuntimeScene;
namespace gd { class Instruction; }
class TiXmlElement;
class EventsCodeGenerationContext;
class EventsEditorItemsAreas;
class EventsEditorSelection;
class Scene;
class MainEditorCommand;
class wxWindow;

/**
 * Timed event
 */
class GD_EXTENSION_API TimedEvent : public gd::BaseEvent
{
    public:
        TimedEvent();
        TimedEvent(const TimedEvent & event);
        virtual ~TimedEvent();

        TimedEvent& operator=(const TimedEvent & event);
        virtual gd::BaseEventSPtr Clone() { return boost::shared_ptr<gd::BaseEvent>(new TimedEvent(*this));}

        virtual bool IsExecutable() const {return true;}
        virtual std::string GenerateEventCode(Game & game, Scene & scene, EventsCodeGenerator & codeGenerator, EventsCodeGenerationContext & context);

        virtual bool CanHaveSubEvents() const {return true;}
        virtual const std::vector < gd::BaseEventSPtr > & GetSubEvents() const {return events;};
        virtual std::vector < gd::BaseEventSPtr > & GetSubEvents() {return events;};
        void SetSubEvents(std::vector < gd::BaseEventSPtr > & subEvents_) {events = subEvents_;};

        const std::vector < gd::Instruction > & GetConditions() const { return conditions; };
        std::vector < gd::Instruction > & GetConditions() { return conditions; };
        void SetConditions(std::vector < gd::Instruction > & conditions_) { conditions = conditions_; };

        const std::vector < gd::Instruction > & GetActions() const { return actions; };
        std::vector < gd::Instruction > & GetActions() { return actions; };
        void SetActions(std::vector < gd::Instruction > & actions_) { actions = actions_; };

        std::string GetName() const { return name; };
        void SetName(std::string name_) { name = name_; };

        std::string GetTimeoutExpression() const { return timeout.GetPlainString(); };
        void SetTimeoutExpression(std::string timeout_) { timeout = gd::Expression(timeout_); };

        virtual std::vector < std::vector<gd::Instruction>* > GetAllConditionsVectors();
        virtual std::vector < std::vector<gd::Instruction>* > GetAllActionsVectors();
        virtual std::vector < gd::Expression* > GetAllExpressions();

        virtual void SaveToXml(TiXmlElement * eventElem) const;
        virtual void LoadFromXml(const TiXmlElement * eventElem);

        /**
         * Called by event editor to draw the event.
         */
        virtual void Render(wxDC & dc, int x, int y, unsigned int width, EventsEditorItemsAreas & areas, EventsEditorSelection & selection);

        /**
         * Must return the height of the event when rendered
         */
        virtual unsigned int GetRenderedHeight(unsigned int width) const;

        /**
         * Called when the user want to edit the event
         */
        virtual EditEventReturnType EditEvent(wxWindow* parent_, Game & game_, Scene & scene_, MainEditorCommand & mainEditorCommand_);

        static std::vector< TimedEvent* > codeGenerationCurrentParents;
        std::vector< TimedEvent* > codeGenerationChildren;

    private:
        void Init(const TimedEvent & event);

        std::string name;
        gd::Expression timeout;
        std::vector < gd::Instruction > conditions;
        std::vector < gd::Instruction > actions;
        std::vector < gd::BaseEventSPtr > events;

        bool nameSelected;
};

#endif // TIMEDEVENT_H

#endif
