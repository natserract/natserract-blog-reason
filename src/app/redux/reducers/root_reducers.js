

import { combineReducers } from 'redux'
import { countReducer } from './post_reducers';

export const RootReducers = combineReducers({
    post: countReducer,
})
