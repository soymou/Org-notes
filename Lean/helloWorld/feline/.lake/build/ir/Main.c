// Lean compiler output
// Module: Main
// Imports: public import Init
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
LEAN_EXPORT lean_object* _lean_main(lean_object*);
size_t lean_usize_mul(size_t, size_t);
uint8_t l_ByteArray_isEmpty(lean_object*);
uint8_t lean_string_dec_eq(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_feline_main___boxed(lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_feline_fileStream___boxed(lean_object*, lean_object*);
uint8_t l_System_FilePath_pathExists(lean_object*);
lean_object* lean_get_stdout();
static size_t lp_feline_bufsize___closed__0;
LEAN_EXPORT lean_object* lp_feline_dump___boxed(lean_object*, lean_object*);
lean_object* lean_stream_of_handle(lean_object*);
lean_object* lean_get_stdin();
lean_object* lean_get_stderr();
lean_object* lean_io_prim_handle_mk(lean_object*, uint8_t);
LEAN_EXPORT lean_object* lp_feline_dump(lean_object*);
static lean_object* lp_feline_fileStream___closed__0;
LEAN_EXPORT size_t lp_feline_bufsize;
LEAN_EXPORT lean_object* lp_feline_dump___boxed__const__1;
LEAN_EXPORT lean_object* lp_feline_process___boxed(lean_object*, lean_object*, lean_object*);
LEAN_EXPORT lean_object* lp_feline_process(uint32_t, lean_object*);
lean_object* l_IO_FS_Stream_putStrLn(lean_object*, lean_object*);
lean_object* lean_string_append(lean_object*, lean_object*);
static lean_object* lp_feline_process___closed__0;
LEAN_EXPORT lean_object* lp_feline_fileStream(lean_object*);
static size_t _init_lp_feline_bufsize___closed__0() {
_start:
{
size_t x_1; size_t x_2; size_t x_3; 
x_1 = 1024;
x_2 = 20;
x_3 = lean_usize_mul(x_2, x_1);
return x_3;
}
}
static size_t _init_lp_feline_bufsize() {
_start:
{
size_t x_1; 
x_1 = lp_feline_bufsize___closed__0;
return x_1;
}
}
static lean_object* _init_lp_feline_dump___boxed__const__1() {
_start:
{
size_t x_1; lean_object* x_2; 
x_1 = lp_feline_bufsize;
x_2 = lean_box_usize(x_1);
return x_2;
}
}
LEAN_EXPORT lean_object* lp_feline_dump(lean_object* x_1) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = lean_ctor_get(x_1, 1);
x_4 = lp_feline_dump___boxed__const__1;
lean_inc_ref(x_3);
x_5 = lean_apply_2(x_3, x_4, lean_box(0));
if (lean_obj_tag(x_5) == 0)
{
uint8_t x_6; 
x_6 = !lean_is_exclusive(x_5);
if (x_6 == 0)
{
lean_object* x_7; uint8_t x_8; 
x_7 = lean_ctor_get(x_5, 0);
x_8 = l_ByteArray_isEmpty(x_7);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; lean_object* x_11; 
lean_free_object(x_5);
x_9 = lean_get_stdout();
x_10 = lean_ctor_get(x_9, 2);
lean_inc_ref(x_10);
lean_dec_ref(x_9);
x_11 = lean_apply_2(x_10, x_7, lean_box(0));
if (lean_obj_tag(x_11) == 0)
{
lean_dec_ref(x_11);
goto _start;
}
else
{
lean_dec_ref(x_1);
return x_11;
}
}
else
{
lean_object* x_13; 
lean_dec(x_7);
lean_dec_ref(x_1);
x_13 = lean_box(0);
lean_ctor_set(x_5, 0, x_13);
return x_5;
}
}
else
{
lean_object* x_14; uint8_t x_15; 
x_14 = lean_ctor_get(x_5, 0);
lean_inc(x_14);
lean_dec(x_5);
x_15 = l_ByteArray_isEmpty(x_14);
if (x_15 == 0)
{
lean_object* x_16; lean_object* x_17; lean_object* x_18; 
x_16 = lean_get_stdout();
x_17 = lean_ctor_get(x_16, 2);
lean_inc_ref(x_17);
lean_dec_ref(x_16);
x_18 = lean_apply_2(x_17, x_14, lean_box(0));
if (lean_obj_tag(x_18) == 0)
{
lean_dec_ref(x_18);
goto _start;
}
else
{
lean_dec_ref(x_1);
return x_18;
}
}
else
{
lean_object* x_20; lean_object* x_21; 
lean_dec(x_14);
lean_dec_ref(x_1);
x_20 = lean_box(0);
x_21 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_21, 0, x_20);
return x_21;
}
}
}
else
{
uint8_t x_22; 
lean_dec_ref(x_1);
x_22 = !lean_is_exclusive(x_5);
if (x_22 == 0)
{
return x_5;
}
else
{
lean_object* x_23; lean_object* x_24; 
x_23 = lean_ctor_get(x_5, 0);
lean_inc(x_23);
lean_dec(x_5);
x_24 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_24, 0, x_23);
return x_24;
}
}
}
}
LEAN_EXPORT lean_object* lp_feline_dump___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_feline_dump(x_1);
return x_3;
}
}
static lean_object* _init_lp_feline_fileStream___closed__0() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("File not found: ", 16, 16);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_feline_fileStream(lean_object* x_1) {
_start:
{
uint8_t x_3; 
x_3 = l_System_FilePath_pathExists(x_1);
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_4 = lean_get_stderr();
x_5 = lp_feline_fileStream___closed__0;
x_6 = lean_string_append(x_5, x_1);
x_7 = l_IO_FS_Stream_putStrLn(x_4, x_6);
if (lean_obj_tag(x_7) == 0)
{
uint8_t x_8; 
x_8 = !lean_is_exclusive(x_7);
if (x_8 == 0)
{
lean_object* x_9; lean_object* x_10; 
x_9 = lean_ctor_get(x_7, 0);
lean_dec(x_9);
x_10 = lean_box(0);
lean_ctor_set(x_7, 0, x_10);
return x_7;
}
else
{
lean_object* x_11; lean_object* x_12; 
lean_dec(x_7);
x_11 = lean_box(0);
x_12 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_12, 0, x_11);
return x_12;
}
}
else
{
uint8_t x_13; 
x_13 = !lean_is_exclusive(x_7);
if (x_13 == 0)
{
return x_7;
}
else
{
lean_object* x_14; lean_object* x_15; 
x_14 = lean_ctor_get(x_7, 0);
lean_inc(x_14);
lean_dec(x_7);
x_15 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_15, 0, x_14);
return x_15;
}
}
}
else
{
uint8_t x_16; lean_object* x_17; 
x_16 = 0;
x_17 = lean_io_prim_handle_mk(x_1, x_16);
if (lean_obj_tag(x_17) == 0)
{
uint8_t x_18; 
x_18 = !lean_is_exclusive(x_17);
if (x_18 == 0)
{
lean_object* x_19; lean_object* x_20; lean_object* x_21; 
x_19 = lean_ctor_get(x_17, 0);
x_20 = lean_stream_of_handle(x_19);
x_21 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_21, 0, x_20);
lean_ctor_set(x_17, 0, x_21);
return x_17;
}
else
{
lean_object* x_22; lean_object* x_23; lean_object* x_24; lean_object* x_25; 
x_22 = lean_ctor_get(x_17, 0);
lean_inc(x_22);
lean_dec(x_17);
x_23 = lean_stream_of_handle(x_22);
x_24 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_24, 0, x_23);
x_25 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_25, 0, x_24);
return x_25;
}
}
else
{
uint8_t x_26; 
x_26 = !lean_is_exclusive(x_17);
if (x_26 == 0)
{
return x_17;
}
else
{
lean_object* x_27; lean_object* x_28; 
x_27 = lean_ctor_get(x_17, 0);
lean_inc(x_27);
lean_dec(x_17);
x_28 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_28, 0, x_27);
return x_28;
}
}
}
}
}
LEAN_EXPORT lean_object* lp_feline_fileStream___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lp_feline_fileStream(x_1);
lean_dec_ref(x_1);
return x_3;
}
}
static lean_object* _init_lp_feline_process___closed__0() {
_start:
{
lean_object* x_1; 
x_1 = lean_mk_string_unchecked("-", 1, 1);
return x_1;
}
}
LEAN_EXPORT lean_object* lp_feline_process(uint32_t x_1, lean_object* x_2) {
_start:
{
if (lean_obj_tag(x_2) == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_box_uint32(x_1);
x_5 = lean_alloc_ctor(0, 1, 0);
lean_ctor_set(x_5, 0, x_4);
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; uint8_t x_9; 
x_6 = lean_ctor_get(x_2, 0);
x_7 = lean_ctor_get(x_2, 1);
x_8 = lp_feline_process___closed__0;
x_9 = lean_string_dec_eq(x_6, x_8);
if (x_9 == 0)
{
lean_object* x_10; 
x_10 = lp_feline_fileStream(x_6);
if (lean_obj_tag(x_10) == 0)
{
lean_object* x_11; 
x_11 = lean_ctor_get(x_10, 0);
lean_inc(x_11);
lean_dec_ref(x_10);
if (lean_obj_tag(x_11) == 0)
{
uint32_t x_12; 
x_12 = 1;
x_1 = x_12;
x_2 = x_7;
goto _start;
}
else
{
lean_object* x_14; lean_object* x_15; 
x_14 = lean_ctor_get(x_11, 0);
lean_inc(x_14);
lean_dec_ref(x_11);
x_15 = lp_feline_dump(x_14);
if (lean_obj_tag(x_15) == 0)
{
lean_dec_ref(x_15);
x_2 = x_7;
goto _start;
}
else
{
uint8_t x_17; 
x_17 = !lean_is_exclusive(x_15);
if (x_17 == 0)
{
return x_15;
}
else
{
lean_object* x_18; lean_object* x_19; 
x_18 = lean_ctor_get(x_15, 0);
lean_inc(x_18);
lean_dec(x_15);
x_19 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_19, 0, x_18);
return x_19;
}
}
}
}
else
{
uint8_t x_20; 
x_20 = !lean_is_exclusive(x_10);
if (x_20 == 0)
{
return x_10;
}
else
{
lean_object* x_21; lean_object* x_22; 
x_21 = lean_ctor_get(x_10, 0);
lean_inc(x_21);
lean_dec(x_10);
x_22 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_22, 0, x_21);
return x_22;
}
}
}
else
{
lean_object* x_23; lean_object* x_24; 
x_23 = lean_get_stdin();
x_24 = lp_feline_dump(x_23);
if (lean_obj_tag(x_24) == 0)
{
lean_dec_ref(x_24);
x_2 = x_7;
goto _start;
}
else
{
uint8_t x_26; 
x_26 = !lean_is_exclusive(x_24);
if (x_26 == 0)
{
return x_24;
}
else
{
lean_object* x_27; lean_object* x_28; 
x_27 = lean_ctor_get(x_24, 0);
lean_inc(x_27);
lean_dec(x_24);
x_28 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_28, 0, x_27);
return x_28;
}
}
}
}
}
}
LEAN_EXPORT lean_object* lp_feline_process___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint32_t x_4; lean_object* x_5; 
x_4 = lean_unbox_uint32(x_1);
lean_dec(x_1);
x_5 = lp_feline_process(x_4, x_2);
lean_dec(x_2);
return x_5;
}
}
LEAN_EXPORT lean_object* _lean_main(lean_object* x_1) {
_start:
{
if (lean_obj_tag(x_1) == 0)
{
uint32_t x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; 
x_3 = 0;
x_4 = lp_feline_process___closed__0;
x_5 = lean_alloc_ctor(1, 2, 0);
lean_ctor_set(x_5, 0, x_4);
lean_ctor_set(x_5, 1, x_1);
x_6 = lp_feline_process(x_3, x_5);
lean_dec_ref(x_5);
return x_6;
}
else
{
uint32_t x_7; lean_object* x_8; 
x_7 = 0;
x_8 = lp_feline_process(x_7, x_1);
lean_dec(x_1);
return x_8;
}
}
}
LEAN_EXPORT lean_object* lp_feline_main___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = _lean_main(x_1);
return x_3;
}
}
lean_object* initialize_Init(uint8_t builtin);
static bool _G_initialized = false;
LEAN_EXPORT lean_object* initialize_feline_Main(uint8_t builtin) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init(builtin);
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
lp_feline_bufsize___closed__0 = _init_lp_feline_bufsize___closed__0();
lp_feline_bufsize = _init_lp_feline_bufsize();
lp_feline_dump___boxed__const__1 = _init_lp_feline_dump___boxed__const__1();
lean_mark_persistent(lp_feline_dump___boxed__const__1);
lp_feline_fileStream___closed__0 = _init_lp_feline_fileStream___closed__0();
lean_mark_persistent(lp_feline_fileStream___closed__0);
lp_feline_process___closed__0 = _init_lp_feline_process___closed__0();
lean_mark_persistent(lp_feline_process___closed__0);
return lean_io_result_mk_ok(lean_box(0));
}
char ** lean_setup_args(int argc, char ** argv);
void lean_initialize_runtime_module();

  #if defined(WIN32) || defined(_WIN32)
  #include <windows.h>
  #endif

  int main(int argc, char ** argv) {
  #if defined(WIN32) || defined(_WIN32)
  SetErrorMode(SEM_FAILCRITICALERRORS);
  SetConsoleOutputCP(CP_UTF8);
  #endif
  lean_object* in; lean_object* res;
argv = lean_setup_args(argc, argv);
lean_initialize_runtime_module();
lean_set_panic_messages(false);
res = initialize_feline_Main(1 /* builtin */);
lean_set_panic_messages(true);
lean_io_mark_end_initialization();
if (lean_io_result_is_ok(res)) {
lean_dec_ref(res);
lean_init_task_manager();
in = lean_box(0);
int i = argc;
while (i > 1) {
 lean_object* n;
 i--;
 n = lean_alloc_ctor(1,2,0); lean_ctor_set(n, 0, lean_mk_string(argv[i])); lean_ctor_set(n, 1, in);
 in = n;
}
res = _lean_main(in);
}
lean_finalize_task_manager();
if (lean_io_result_is_ok(res)) {
  int ret = lean_unbox_uint32(lean_io_result_get_value(res));
  lean_dec_ref(res);
  return ret;
} else {
  lean_io_result_show_error(res);
  lean_dec_ref(res);
  return 1;
}
}
#ifdef __cplusplus
}
#endif
