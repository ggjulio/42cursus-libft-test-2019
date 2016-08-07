/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <alelievr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 16:42:40 by alelievr          #+#    #+#             */
/*   Updated: 2016/08/07 16:51:04 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_test.h"

#define INIT_VSFUN(ptr, name, fun) typeof(fun) *name = (ptr) ? (typeof(fun) *)ptr : fun;

#define KILOBYTE	(1024llu)
#define MEGABYTE	(KILOBYTE * KILOBYTE)
#define GIGABYTE	(KILOBYTE * KILOBYTE * KILOBYTE)

#define			add_fun_subbench(x) add_fun_subbench_(x, (char *)# x)
void			add_fun_subbench_(void (*fun)(void *ptr1, void *ptr2), char *funname) {
	static int		index = 0;

	if (index >= SUBTEST_SIZE)
		return ;
	(void)funname;
	fun_subbench_table[index].fun_name = current_fun_name;
	fun_subbench_table[index].fun_bench_ptr = fun;
	index++;
	total_subtest++;
}

////////////////////////////////
//         ft_memset          //
////////////////////////////////

void			bench_ft_memset_fatbench(void *ptr, void *vsptr) {
	typeof(memset)	*ft_memset = ptr;
	INIT_VSFUN(vsptr, vsfun, memset);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 64;
			char	*b1 = (char *)malloc(sizeof(char) * size);
			char	*b2 = (char *)malloc(sizeof(char) * size);
			,
			vsfun(b1, 'A', size);
			,
			ft_memset(b2, 'A', size);
			);
}

void			bench_ft_memset_medbench(void *ptr, void *vsptr) {
	typeof(memset)	*ft_memset = ptr;
	INIT_VSFUN(vsptr, vsfun, memset);
	SET_BENCHTYPE(BENCH_MEDIUM);
	SET_BENCHITER(KILOBYTE * 256);

	SANDBOX_BENCH(
			size_t	size = KILOBYTE * 8;
			char	*b1 = (char *)malloc(sizeof(char) * size);
			char	*b2 = (char *)malloc(sizeof(char) * size);
			,
			vsfun(b1, 'A', size);
			,
			ft_memset(b2, 'A', size);
			);
}

void			bench_ft_memset_smallbench(void *ptr, void *vsptr) {
	typeof(memset)	*ft_memset = ptr;
	INIT_VSFUN(vsptr, vsfun, memset);
	SET_BENCHTYPE(BENCH_SMALL);
	SET_BENCHITER(MEGABYTE * 16);

	SANDBOX_BENCH(
			size_t	size = 32;
			char	*b1 = (char *)malloc(sizeof(char) * size);
			char	*b2 = (char *)malloc(sizeof(char) * size);
			,
			vsfun(b1, 'A', size);
			,
			ft_memset(b2, 'A', size);
			);
}

void            bench_ft_memset(void) {
	add_fun_subbench(bench_ft_memset_fatbench);
	add_fun_subbench(bench_ft_memset_medbench);
	add_fun_subbench(bench_ft_memset_smallbench);
}

////////////////////////////////
//         ft_bzero           //
////////////////////////////////

void			bench_ft_bzero_fatbench(void *ptr, void *vsptr) {
	typeof(bzero)	*ft_bzero = ptr;
	INIT_VSFUN(vsptr, vsfun, bzero);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 128;
			char	*str = (char *)malloc(sizeof(char) * size);
			char	*str2 = (char *)malloc(sizeof(char) * size);

			memset(str, 'a', size);
			memset(str2, 'a', size);
			,
			vsfun(str, size);
			,
			ft_bzero(str2, size);
			);
}

void            bench_ft_bzero(void){
	add_fun_subbench(bench_ft_bzero_fatbench);
}

////////////////////////////////
//         ft_memcpy          //
////////////////////////////////

void			bench_ft_memcpy_fatbench(void *ptr, void *vsptr) {
	typeof(memcpy)	*ft_memcpy = ptr;
	INIT_VSFUN(vsptr, vsfun, memcpy);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 32;
			char	*src = malloc(size);
			char	*buff1 = malloc(size);
			char	*buff2 = malloc(size);

			memset(src, 'A', size);
			,
			ft_memcpy(buff1, src, size);
			,
			ft_memcpy(buff2, src, size);
			);
	(void)vsfun;
}
void            bench_ft_memcpy(void){
	add_fun_subbench(bench_ft_memcpy_fatbench);
}

////////////////////////////////
//         ft_memccpy         //
////////////////////////////////

void			bench_ft_memccpy_fatbench(void *ptr, void *vsptr) {
	typeof(memccpy)	*ft_memccpy = ptr;
	INIT_VSFUN(vsptr, vsfun, memccpy);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 16;
			char	*src1 = malloc(size);
			char	*src2 = malloc(size);
			char	*buff1 = malloc(size);
			char	*buff2 = malloc(size);

			memset(src1, 'A', size);
			memset(src2, 'A', size);
			,
			vsfun(buff1, src1, '\\', size);
			,
			ft_memccpy(buff2, src2, '\\', size);
			);
}

void            bench_ft_memccpy(void){
	add_fun_subbench(bench_ft_memccpy_fatbench);
}

////////////////////////////////
//         ft_memmove         //
////////////////////////////////

void			bench_ft_memmove_fatbench(void *ptr, void *vsptr) {
	typeof(memmove)		*ft_memmove = ptr;
	INIT_VSFUN(vsptr, vsfun, memmove);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			int		size = MEGABYTE * 32;
			char	*dst1 = (char *)malloc(sizeof(char) * size);
			char	*dst2 = (char *)malloc(sizeof(char) * size);
			char	*data = (char *)malloc(sizeof(char) * size);

			memset(data, 'A', size);
			,
			vsfun(dst1, data, size);
			,
			ft_memmove(dst2, data, size);
			);
}

void            bench_ft_memmove(void){
	add_fun_subbench(bench_ft_memmove_fatbench);
}

////////////////////////////////
//         ft_memchr          //
////////////////////////////////

void			bench_ft_memchr_fatbench(void *ptr, void *vsptr) {
	typeof(memchr)		*ft_memchr = ptr;
	INIT_VSFUN(vsptr, vsfun, memchr);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t			size = MEGABYTE * 128;
			char			*src = malloc(size);

			memset(src, 'A', size);
			,
			vsfun(src, '\xde', size);
			,
			ft_memchr(src, '\xde', size);
			);
}

void            bench_ft_memchr(void) {
	add_fun_subbench(bench_ft_memchr_fatbench);
}

////////////////////////////////
//         ft_memcmp          //
////////////////////////////////

void			bench_ft_memcmp_fatbench(void *ptr, void *vsptr) {
	typeof(memcmp)		*ft_memcmp = ptr;
	INIT_VSFUN(vsptr, vsfun, memcmp);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 64;
			uint8_t	*s1 = malloc(sizeof(uint8_t) * size);
			uint8_t	*s2 = malloc(sizeof(uint8_t) * size);

			memset(s1, 'A', size);
			memset(s2, 'A', size);
			,
			vsfun(s1, s2, size);
			,
			ft_memcmp(s1, s2, size);
			);
}

void            bench_ft_memcmp(void){
	add_fun_subbench(bench_ft_memcmp_fatbench);
}

////////////////////////////////
//         ft_strlen          //
////////////////////////////////

void			bench_ft_strlen_fatbench(void *ptr, void *vsptr) {
	typeof(strlen)	*ft_strlen = ptr;
	INIT_VSFUN(vsptr, vsfun, strlen);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 128;
			char	*str = malloc(size + 1);

			memset(str, 'A', size);
			str[size] = 0;
			,
			vsfun(str);
			,
			ft_strlen(str);
			);
}

void            bench_ft_strlen(void) {
	add_fun_subbench(bench_ft_strlen_fatbench);
}

////////////////////////////////
//         ft_strdup          //
////////////////////////////////

void			bench_ft_strdup_fatbench(void *ptr, void *vsptr) {
	typeof(strdup)	*ft_strdup = ptr;
	INIT_VSFUN(vsptr, vsfun, strdup);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 16;
			char	*str = malloc(size + 1);

			memset(str, 'A', size);
			str[size] = 0;
			,
			vsfun(str);
			,
			ft_strdup(str);
			);

}

void            bench_ft_strdup(void) {
	add_fun_subbench(bench_ft_strdup_fatbench);
}

////////////////////////////////
//         ft_strcpy          //
////////////////////////////////

void			bench_ft_strcpy_fatbench(void *ptr, void *vsptr) {
	typeof(strcpy)	*ft_strcpy = ptr;
	INIT_VSFUN(vsptr, vsfun, strcpy);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 64;
			char	*src = malloc(size + 1);
			char	*dst1 = malloc(size + 1);
			char	*dst2 = malloc(size + 1);

			memset(src, 'A', size);
			src[size] = 0;
			,
			vsfun(dst1, src);
			,
			ft_strcpy(dst2, src);
			);
}

void            bench_ft_strcpy(void) {
	add_fun_subbench(bench_ft_strcpy_fatbench);
}

////////////////////////////////
//         ft_strncpy         //
////////////////////////////////

void			bench_ft_strncpy_fatbench(void *ptr, void *vsptr) {
	typeof(strncpy)	*ft_strncpy = ptr;
	INIT_VSFUN(vsptr, vsfun, strncpy);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 64;
			char	*src = malloc(size + 1);
			char	*dst1 = malloc(size + 1);
			char	*dst2 = malloc(size + 1);

			memset(src, 'A', size);
			src[size] = 0;
			,
			vsfun(dst1, src, size);
			,
			ft_strncpy(dst2, src, size);
			);
}

void            bench_ft_strncpy(void){
	add_fun_subbench(bench_ft_strncpy_fatbench);
}

////////////////////////////////
//         ft_strcat          //
////////////////////////////////

void			bench_ft_strcat_fatbench(void *ptr, void *vsptr) {
	typeof(strcat)	*ft_strcat = ptr;
	INIT_VSFUN(vsptr, vsfun, strcat);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 256;
			char	*str = malloc(size + 1);
			char	*buff1 = malloc(size + 1);
			char	*buff2 = malloc(size + 1);

			*buff1 = 0;
			*buff2 = 0;
			memset(str, 'A', size / current_benchiter);
			str[size] = 0;
			,
			vsfun(buff1, str);
			,
			ft_strcat(buff2, str);
			);
}

void            bench_ft_strcat(void){
	add_fun_subbench(bench_ft_strcat_fatbench);
}

////////////////////////////////
//         ft_strncat         //
////////////////////////////////

void			bench_ft_strncat_fatbench(void *ptr, void *vsptr) {
	typeof(strncat)	*ft_strncat = ptr;
	INIT_VSFUN(vsptr, vsfun, strncat);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 128;
			char	*str = malloc(size + 1);
			char	*buff1 = malloc(size + 1);
			char	*buff2 = malloc(size + 1);

			*buff1 = 0;
			*buff2 = 0;
			memset(str, 'A', size / current_benchiter);
			str[size] = 0;
			,
			vsfun(buff1, str, size);
			,
			ft_strncat(buff2, str, size);
			);
}

void            bench_ft_strncat(void){
	add_fun_subbench(bench_ft_strncat_fatbench);
}

////////////////////////////////
//         ft_strlcat         //
////////////////////////////////

void			bench_ft_strlcat_fatbench(void *ptr, void *vsptr) {
	typeof(strlcat)	*ft_strlcat = ptr;
	INIT_VSFUN(vsptr, vsfun, strlcat);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 32;
			char	*str = malloc(size + 1);
			char	*buff1 = malloc(size + 1);
			char	*buff2 = malloc(size + 1);

			*buff1 = 0;
			*buff2 = 0;
			memset(str, 'A', size);
			str[size] = 0;
			,
			vsfun(buff1, str, size);
			,
			ft_strlcat(buff2, str, size);
			);
}

void            bench_ft_strlcat(void){
	add_fun_subbench(bench_ft_strlcat_fatbench);
}

////////////////////////////////
//         ft_strchr          //
////////////////////////////////

void			bench_ft_strchr_fatbench(void *ptr, void *vsptr) {
	typeof(strchr)	*ft_strchr = ptr;
	INIT_VSFUN(vsptr, vsfun, strchr);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 128;
			char	*src = malloc(size + 1);

			memset(src, 'A', size);
			src[size] = 0;
			,
			vsfun(src, 'B');
			,
			ft_strchr(src, 'B');
			);
}

void            bench_ft_strchr(void){
	add_fun_subbench(bench_ft_strchr_fatbench);
}

////////////////////////////////
//         ft_strrchr         //
////////////////////////////////

void			bench_ft_strrchr_fatbench(void *ptr, void *vsptr) {
	typeof(strrchr)	*ft_strrchr = ptr;
	INIT_VSFUN(vsptr, vsfun, strrchr);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 32;
			char	*src = malloc(size + 1);

			memset(src, 'A', size);
			src[size] = 0;
			,
			vsfun(src, 'B');
			,
			ft_strrchr(src, 'B');
			);
}

void            bench_ft_strrchr(void){
	add_fun_subbench(bench_ft_strrchr_fatbench);
}

////////////////////////////////
//         ft_strstr          //
////////////////////////////////

void			bench_ft_strstr_fatbench(void *ptr, void *vsptr) {
	typeof(strstr)	*ft_strstr = ptr;
	INIT_VSFUN(vsptr, vsfun, strstr);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 8;
			char	*s1 = malloc(size + 1);
			char	*s2 = "AAAAB";

			memset(s1, 'A', size);
			s1[size] = 0;
			,
			vsfun(s1, s2);
			,
			ft_strstr(s1, s2);
			);
}

void            bench_ft_strstr(void){
	add_fun_subbench(bench_ft_strstr_fatbench);
}

////////////////////////////////
//         ft_strnstr         //
////////////////////////////////

void			bench_ft_strnstr_fatbench(void *ptr, void *vsptr) {
	typeof(strnstr)	*ft_strnstr = ptr;
	INIT_VSFUN(vsptr, vsfun, strnstr);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 32;
			char	*s2 = "AAAAB";
			char	*s1 = malloc(size + 1);

			memset(s1, 'A', size);
			s1[size] = 0;
			,
			vsfun(s1, s2, size);
			,
			ft_strnstr(s1, s2, size);
			);
}

void            bench_ft_strnstr(void){
	add_fun_subbench(bench_ft_strnstr_fatbench);
}

////////////////////////////////
//         ft_strcmp          //
////////////////////////////////

void			bench_ft_strcmp_fatbench(void *ptr, void *vsptr) {
	typeof(strcmp)	*ft_strcmp = ptr;
	INIT_VSFUN(vsptr, vsfun, strcmp);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 128;
			char	*s1 = malloc(size + 1);
			char	*s2 = malloc(size + 1);

			memset(s1, 'A', size);
			memset(s2, 'A', size);
			s1[size] = s2[size] = 0;

			,
			vsfun(s1, s2);
			,
			ft_strcmp(s1, s2);
			);
}

void            bench_ft_strcmp(void){
	add_fun_subbench(bench_ft_strcmp_fatbench);
}

////////////////////////////////
//         ft_strncmp         //
////////////////////////////////

void			bench_ft_strncmp_fatbench(void *ptr, void *vsptr) {
	typeof(strncmp)	*ft_strncmp = ptr;
	INIT_VSFUN(vsptr, vsfun, strncmp);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 128;
			char	*s1 = malloc(size + 1);
			char	*s2 = malloc(size + 1);

			memset(s1, 'A', size);
			memset(s2, 'A', size);
			s1[size] = s2[size] = 0;

			,
			vsfun(s1, s2, size);
			,
			ft_strncmp(s1, s2, size);
			);
}

void            bench_ft_strncmp(void){
	add_fun_subbench(bench_ft_strncmp_fatbench);
}

////////////////////////////////
//         ft_atoi            //
////////////////////////////////

void			bench_ft_atoi_fatbench(void *ptr, void *vsptr) {
	typeof(atoi)	*ft_atoi = ptr;
	INIT_VSFUN(vsptr, vsfun, atoi);
	SET_BENCHTYPE(BENCH_FAT);
	SET_BENCHITER(16);

	SANDBOX_BENCH(
			size_t	size = MEGABYTE * 64;
			char	*nbrs = malloc(size);

			bzero(nbrs, size);
			srand(time(NULL) + clock());
			for (int i = 0; i < 1000000; i++)
				sprintf(nbrs + (i * 14), "%-11i", rand());
			,
			for (int i = 0; i < 1000000; i++)
				vsfun(nbrs + (i * 14));
			,
			for (int i = 0; i < 1000000; i++)
				ft_atoi(nbrs + (i * 14));
			);
}

void            bench_ft_atoi(void){
	add_fun_subbench(bench_ft_atoi_fatbench);
}