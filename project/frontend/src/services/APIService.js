import axios from 'axios'
import Vue from 'vue'
import VueAxios from 'vue-axios'
import { API_URL} from '@/services/config'

const APIService = {
    init () {
        Vue.use(VueAxios, axios)
        Vue.axios.defaults.baseURL = API_URL
    },
    get (resource, slug=''){
        return Vue.axios
            .get(`${resource}\${slug}`)
            .catch((error) => {
                throw new Error(`APIService ${error}`)
            })
    },
}    

export default APIService