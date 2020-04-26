import { CountActionTypes } from '../types';
import { action } from 'typesafe-actions';

export const increment = () => action(CountActionTypes.INCREMENT);
export const decrement = () => action(CountActionTypes.DECREMENT);
