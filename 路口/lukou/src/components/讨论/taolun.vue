<template>
    <div class="container">
      <div class="lu_list">
        <div class="list" v-for="item in list" >
          <div class="listitem">
            <div class="listl">
              <div class="title">{{item.group.name}}</div>
              <div class="shortText">{{item.group.introduction}}</div>
            </div>
            <div class="listr"><img :src="item.group.imageUrl" alt=""></div>
          </div>
          <div class="author">
            <span class="smallAvatars" v-for="(sitem,index) in item.group.userList" v-if="index<3">
            <span class="smallAvatar"><img :src="sitem.smallAvatar" alt=""></span></span>
            <span class="name">{{item.group.tip}}</span>
          </div>
        </div>
      </div>
    </div>
</template>

<script>
    export default {
        data() {
            return {
              list:[]
            }
        },
        created () {
          this.$axios.get('/api/taolunlist')
            .then((res) =>{
              res = res.data
              if(res.error === 0){
                this.list = res.data
              }
            })
            .catch((error) =>{
              alert(error)
            })
        }
    }
</script>

<style lang="less" scoped>
  .container {
    position: absolute;
    top: 86px;
    bottom: 58px;
    overflow: auto;
    width: 100%;
    .list{
      margin-top: 4px;
      padding: 0 12px 10px 14px;
      box-sizing: border-box;
      width: 100%;
      border-bottom: 1px solid #dfdfdf;
      &:last-child{
        border-bottom:none;
      }
      .listitem{
        position: relative;
        height: 120px;
        margin-bottom: 16px;
        .listl{
          display: inline-block;
          width: 62%;
          .title{
            margin-top: 4px;
            font-size: 17px;
            margin-bottom: 8px;
            line-height: 1.4;
            color: black;
          }
          .shortText{
            line-height: 1.5;
            font-size: 14px;
            height: 40px;
            overflow: hidden;
            text-overflow: ellipsis;
            /*white-space: nowrap;*/
            word-break: break-all;
            display: -webkit-box;
            -webkit-box-orient:vertical;
            -webkit-line-clamp:2;
            color: #949494;
          }
        }
        .listr{
          position: absolute;
          right: 0px;
          display: inline-block;
          width: 36%;
          height: 100px;
          vertical-align: top;
          img{
            width: 126px;
            height: 100px;
          }
        }
      }
      .author{
        color: #8a999a;
        font-size: 13px;
        height: 30px;
        line-height: 30px;
        position: relative;
        .smallAvatar{
          display: inline-block;
          margin-right: -6px;
          img{
            border-radius: 50%;
            width: 28px;
            height: 28px;
          }
        }
        .name{
          display: inline-block;
          margin-left: 8px;
          vertical-align: top;
        }
        .commentCount{
          display: inline-block;
          vertical-align: top;
        }
        .like{
          position: absolute;
          right: 2px;
          .icon{
            font-size: 20px;
          }
        }
      }
    }
  }

</style>
