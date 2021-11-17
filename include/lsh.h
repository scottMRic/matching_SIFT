#include "knn_brute.h"     

typedef __uint64_t uint64_t;
void make_vec(int dim, des_t  &vec);
float dot(des_t v1, des_t v2);

void host_lsh(des_t *q_points, des_t *r_points, int n_q, int n_r, float4 *sorted, int nbits, int l, int max_dist = 1) ; 

void gpu_lsh(des_t * q_points, des_t * r_points, int n_q, int n_r, float4  * sorted, int nbits, int l, int max_dist = 1);

// buckets start value 
__global__ void set_bucket_start(int * helper, int * bucket_start, int l, int n_r); 
__global__ void set_helper(int * helper, int * code, int * index) ; 

//random  vector
__device__ inline float random_float(uint64_t seed, int idx) ; 
__global__ void random_vector(uint64_t seed, des_t *vec) ; 


__device__ inline void reduce(float &var); 
__device__ void change_bit(int n, int k, int dir, int pos, int start) ; 

__global__ void hamming(int * neighbouring_buckets, int dist, int size, int * bucket ) ; 
//make bucket  
__global__ void dot_gpu(des_t *  rand, des_t * points, float *dot); 
__global__ void set_bit(int *buckets, int nbits, float * dot); 

__global__ void set_bucket(int * index, int * index_copy, int n); 

void lsh_test(des_t *q_points, des_t *r_points, int n_q, int n_r, float4 *sorted, int nbits, int l, int max_dist) ; 

void search_bucket(float4 &min, int bucket, int start, int * code, int * index, des_t * r_p, des_t * q_p, int size_r, int x); 


__global__ void find_all_neigbours_dist_1(int to_read, int * neighbouring_buckets, int nbits, int * bucket, int n_buckets ) ; 

__global__ void find_all_neigbours_dist_2_odd(int to_read, int * neighbouring_buckets, int nbits, int * bucket ) ;

__global__ void find_all_neigbours_dist_2_pair(int to_read, int * neighbouring_buckets, int nbits, int * bucket )  ; 