import { Reducer } from 'redux'
import { CountActionTypes, ICountState, CountActions } from '../types';

const initial_state: ICountState = {
    count: 0
};

export const countReducer: Reducer<ICountState, CountActions> = (state = initial_state, action): ICountState => {
    switch(action.type){
        case CountActionTypes.INCREMENT: {
            return {
                count: state.count + 1
            }
        }
        case CountActionTypes.DECREMENT: {
            return {
                count: state.count - 1
            }
        }
        default: return state
    }
}
