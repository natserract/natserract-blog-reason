export enum FileSystemActionTypes {
    REQUEST = '@@filesystem/REQUEST',
    LOAD = '@@filesystem/LOAD',
    ERROR = '@@filesystem/ERROR'
}

export interface FileSystemState {
    loading: boolean,
    errors: string,
    dir: string[],
    description: string[]
}

export type FileSystemActions = 
    | { type: FileSystemActionTypes.REQUEST }
    | { type: FileSystemActionTypes.LOAD, payload: { 
        data: string[],
        article_description: string[]
    }}
    | { type: FileSystemActionTypes.ERROR, payload: { message: string } }