const listReducer = (state = [], action) => {

  switch (action.type) {
    case 'ADD_ITEM':
      return state.concat(action.payload);
      break;
    default:
      return state;
  }
};

export default listReducer;
