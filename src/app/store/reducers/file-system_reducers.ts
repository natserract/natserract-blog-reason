import { Reducer } from 'redux'
import { FileSystemActionTypes, FileSystemActions, FileSystemState } from '../types';

const initial_state: FileSystemState = {
    loading: false,
    errors: undefined,
    dir: []
};

export const fileSystemReducer: Reducer<FileSystemState, FileSystemActions> = (state = initial_state, action): FileSystemState => {
    switch(action.type){
        case FileSystemActionTypes.REQUEST: {
            return {
                ...state,
                loading: true
            }
        }
        case FileSystemActionTypes.LOAD: {
            return {
                ...state,
                loading: false,
                dir: action.payload.data
            }
        }
        case FileSystemActionTypes.ERROR: {
            return {
                ...state,
                loading: false,
                errors: action.payload.message
            }
        }
        default: return state
    }
}
