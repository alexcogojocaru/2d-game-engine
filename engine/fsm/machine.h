#include <iostream>

namespace engine
{
	namespace fsm
	{
		class FiniteStateMachine
		{
		private:
			class State* currentState_;

		public:
			void setState(State* state);
		};
	}
}