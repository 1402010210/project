import Vue from 'vue'
import Vuex from 'vuex'
import mutations from './mutations'
import * as actions from './actions'
import header from './modules/header'
Vue.use(Vuex)

export default new Vuex.Store({
  mutations,
  actions,
  modules: {
    header
  }
})
