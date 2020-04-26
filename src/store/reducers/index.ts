

import { combineReducers } from 'redux'
import { countReducer } from './count_reducers';
import { fileSystemReducer } from './file-system_reducers';

export const RootReducers = combineReducers({
    countState: countReducer,
    fileSystemState: fileSystemReducer
})

export type RootState = ReturnType<typeof RootReducers>