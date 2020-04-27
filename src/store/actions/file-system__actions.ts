import { FileSystemState, FileSystemActions, FileSystemActionTypes } from '../types';
import { ActionCreator } from 'redux';
import { ThunkAction } from 'redux-thunk';
import { action } from 'typesafe-actions';
import { findMarkdownPath } from '../helpers/lib';
import { findDirectory } from '../helpers/lib';

export const fetch_request = () => action(FileSystemActionTypes.REQUEST);

export const fetch_dir: ActionCreator<ThunkAction<Promise<any>, FileSystemState, null, FileSystemActions>> = 
() => async dispatch => {
    dispatch(fetch_request());

    await findDirectory('../../../posts/')
            .then((dirs) => {
                findMarkdownPath(dirs).then(md_description => {
                    dispatch({
                        type: FileSystemActionTypes.LOAD,
                        payload: {
                            data: dirs,
                            article_description: md_description
                        }
                    });
                })
             
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