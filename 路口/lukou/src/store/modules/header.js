import * as types from '../mutation-types'
const state = {
  index: 0,
  timer: 1,
  length: 0
}

const mutations = {
  [types.RECEIVE_LENGTH](state, length) {
    state.length = length
  }
}

// 计时器开始轮播图
const actions = {
  startHeaderTransition({commit, state}, {obj , bj}) {
    // console.log(obj,bj)
    clearInterval(state.timer)
    state.timer = setInterval(() => {
      state.index++
    commit(types.ADD_TRANSITION, {obj})
    let offsetX = -state.index * 375 + 'px'
    // let num = state.index
    commit(types.SET_TRANSLATE, {x: offsetX, y: 0, z: 0, obj})
    let pages=bj.getElementsByTagName('li')
    // commit(types.SET_Page, {num ,pages})
    for (var i = 0; i < 3; i++) {
      pages[i].className = "";
    }
    var num = state.index;
    if (state.index >= 3) {
      num = 0;
    }
    pages[num].className = 'now'
  }, 3500)
  }
}

export default {
  state,
  mutations,
  actions
}
