
var { RootReducers } = require('../reducers/root_reducers');
var { createStore } = require('redux');

 const lib = {
    store: createStore(RootReducers),
    getState: function() {
        return this.store.getState()
    },
    dispatch: function() {
        return this.store.dispatch({ type: 'INCREMENT' })
    }
};

module.exports = lib;