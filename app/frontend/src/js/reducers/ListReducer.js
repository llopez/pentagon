const listReducer = (state = {items: []}, action) => {

  switch (action.type) {
    case 'ADD_ITEM':
      return state.items.concat(action.payload);
      break;
    case 'RECEIVE_ITEMS':
      return Object.assign(state, {items: action.payload});
      break;
    default:
      return state;
  }
};

export default listReducer;
