import Vue from 'vue'
import Vuex from 'vuex'

import Senators from './endpoints.module'

Vue.use(Vuex)

export default new Vuex.Store({
    modules: {
        senators
    }
})