// Code generated by gobind. DO NOT EDIT.

// JNI functions for the Go <=> Java bridge.
//
//   autogenerated by gobind -lang=java 

#include <android/log.h>
#include <stdint.h>
#include "seq.h"
#include "_cgo_export.h"
#include "universe.h"

jclass proxy_class__error;
jmethodID proxy_class__error_cons;
static jmethodID mid_error_Error;

JNIEXPORT void JNICALL
Java_go_Universe__1init(JNIEnv *env, jclass _unused) {
	jclass clazz;
	clazz = (*env)->FindClass(env, "go/Universe$proxyerror");
	proxy_class__error = (*env)->NewGlobalRef(env, clazz);
	proxy_class__error_cons = (*env)->GetMethodID(env, clazz, "<init>", "(I)V");
	clazz = (*env)->FindClass(env, "java/lang/Throwable");
	mid_error_Error = (*env)->GetMethodID(env, clazz, "getMessage", "()Ljava/lang/String;");
}

JNIEXPORT jstring JNICALL
Java_go_Universe_00024proxyerror_error(JNIEnv* env, jobject __this__) {
	int32_t o = go_seq_to_refnum_go(env, __this__);
	nstring r0 = proxy_error_Error(o);
	jstring _r0 = go_seq_to_java_string(env, r0);
	return _r0;
}

nstring cproxy_error_Error(int32_t refnum) {
	JNIEnv *env = go_seq_push_local_frame(0);
	jobject o = go_seq_from_refnum(env, refnum, proxy_class__error, proxy_class__error_cons);
	jstring res = (*env)->CallObjectMethod(env, o, mid_error_Error);
	nstring _res = go_seq_from_java_string(env, res);
	go_seq_pop_local_frame(env);
	return _res;
}

