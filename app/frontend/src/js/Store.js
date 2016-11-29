import { createStore } from 'redux';
import listReducer from './reducers/ListReducer';

const store = createStore(listReducer);


export default store;

window.store = store;
