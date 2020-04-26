export enum CountActionTypes {
    INCREMENT = '@@count/INCREMENT',
    DECREMENT = '@@count/DECREMENT',
}

export interface ICountState {
    count: number,
}

export type CountActions = 
    | { type: CountActionTypes.INCREMENT }
    | { type: CountActionTypes.DECREMENT }