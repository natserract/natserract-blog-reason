
const INITIAL_STATE: number = 0
export const countReducer = (state = INITIAL_STATE, action) => {
    switch(action.type){
        case 'INCREMENT':
            return state + 1
        case 'DECREMENT':
            return state - 1
        default:
            return state
    }
}
