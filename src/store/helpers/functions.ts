
import { RootReducers } from '../reducers';
import { createStore, compose, applyMiddleware } from 'redux';
import * as Action from '../actions';
import thunk from 'redux-thunk';

type Act = 
    | "@@count/INCREMENT"
    | "@@count/DECREMENT"
    | "@@filesystem/REQUEST"
    | "@@filesystem/LOAD";

const composeEnchancers  = (window as any).__REDUX_DEVTOOLS_EXTENSION_COMPOSE__ || compose;
const enchancers = composeEnchancers(applyMiddleware(thunk));

const functions = {
    store: createStore(
        RootReducers,
        enchancers
    ),
    getState: function() {
        return this.store.getState()
    },
    dispatch: function(action: Act) {
        switch (action) {
            case "@@count/INCREMENT": {
                return this.store.dispatch(Action.increment())
            }
            case "@@count/DECREMENT": {
                return this.store.dispatch(Action.decrement())
            }
            case "@@filesystem/REQUEST": {
                return this.store.dispatch(Action.fetch_request())
            }
            case "@@filesystem/LOAD": {
                return this.store.dispatch(Action.fetch_dir())
            }
            default: {
                console.error(
                    "Dispatch action not found!"
                );
                throw Error();
            }
        }
    }
};



export = functions;