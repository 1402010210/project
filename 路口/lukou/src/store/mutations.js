import * as types from './mutation-types'

export default {
  [types.ADD_TRANSITION](state, {obj}) {
    obj.style.transition = 'all 0.5s'
    obj.style.webkitTransition = 'all 0.5s'
  },
  [types.REMOVE_TRANSITION](state, {obj}) {
    obj.style.transition = 'none'
    obj.style.webkitTransition = 'none'
  },
  [types.SET_TRANSLATE](state, {x, y, z, obj}) {
    obj.style.transform = `translate3d(${x},${y},${z})`
    obj.style.webkitTransform = `translate3d(${x},${y},${z})`
  },
  [types.SET_Page](state,{index,pages}) {
    console.log(index,pages)
    for (var i = 0; i < 3; i++) {
      pages[i].className = "";
    }
    var num = state.index;
    if (state.index >= 4) {
      num = 1;
    }
    pages[num - 1].className = 'now'
}
}


