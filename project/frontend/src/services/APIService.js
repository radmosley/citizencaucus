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


constructor(){

    }
    /* The othermethods go here*/
    getSenators(){
        const url = `${API_URL}/api/senators`;
        return axios.get(url).then(response => response.data);
    }
/*    getSenatorsById(sid){
        const url = `${API_URL}/api/senators/${sid}`;
        return axios.get(url).then(response => response.data);
    }*/
}