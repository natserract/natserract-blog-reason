import { FileSystemState, FileSystemActions, FileSystemActionTypes } from '../types';
import { ActionCreator } from 'redux';
import { ThunkAction } from 'redux-thunk';
import { action } from 'typesafe-actions';

export const fetch_request = () => action(FileSystemActionTypes.REQUEST);

export const fetch_dir: ActionCreator<ThunkAction<Promise<any>, FileSystemState, null, FileSystemActions>> = 
() => async dispatch => {
    dispatch(fetch_request());

    const regex = /title=\"[^\"]*?\"[^>]*?/g;
    const regex_sec = /\"[^\"]*\"[^]*?/g;
    let empty_str = "";

    const path = '../../posts/';

    await fetch(path, { mode: 'no-cors' })
        .then(res => res.text())
        .then(data => {
            empty_str = data;

            let res_str = empty_str.match(regex);
            let regex_result_str = res_str.join("").match(regex_sec).join(",");
            let final_result = regex_result_str.replace(/\"[^\"]*?/g, '').split(",").slice(1);
            
            dispatch({
                type: FileSystemActionTypes.LOAD,
                payload: {
                    data: final_result
                }
            });
        })

        .catch(err => {
            dispatch({
                type: FileSystemActionTypes.ERROR,
                payload: {
                    message: err
                }
            });
        });
}