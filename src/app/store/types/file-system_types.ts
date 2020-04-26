export enum FileSystemActionTypes {
    REQUEST = '@@filesystem/REQUEST',
    LOAD = '@@filesystem/LOAD',
    ERROR = '@@filesystem/ERROR'
}

export interface FileSystemState {
    loading: boolean,
    errors: string,
    dir: string[],
}

export type FileSystemActions = 
    | { type: FileSystemActionTypes.REQUEST }
    | { type: FileSystemActionTypes.LOAD, payload: { data: string[] }}
    | { type: FileSystemActionTypes.ERROR, payload: { message: string } }