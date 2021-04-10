#include <jni.h>
#include <string>

#include <c4a/core/log.h>
#include <gst/gst.h>

static constexpr auto LGR = "native-lib";

static void testLogging()
{
    c4a::core::Logging::initConsoleLogging();
    LOG_INFO(LGR, "Hello from C++");
}

#if 0
static void
gst_native_init (JNIEnv * env, jobject thiz)
{
    CustomData *data = g_new0 (CustomData, 1);
    SET_CUSTOM_DATA (env, thiz, custom_data_field_id, data);
    GST_DEBUG_CATEGORY_INIT (debug_category, "tutorial-2", 0,
                             "Android tutorial 2");
    gst_debug_set_threshold_for_name ("tutorial-2", GST_LEVEL_DEBUG);
    GST_DEBUG ("Created CustomData at %p", data);
    data->app = (*env)->NewGlobalRef (env, thiz);
    GST_DEBUG ("Created GlobalRef for app object at %p", data->app);
    pthread_create (&gst_app_thread, NULL, &app_function, data);
}
#endif


extern "C" JNIEXPORT jstring JNICALL
Java_com_tbg_capture_MainActivity_stringFromJNI(JNIEnv* env, jobject thiz)
{
    gst_init(nullptr, nullptr);
    char* version_utf8 = gst_version_string();
    auto version_jstring = env->NewStringUTF(version_utf8);
    g_free(version_utf8);
    return version_jstring;
}



#if 0
/*
 * Java Bindings
 */
static jstring
gst_native_get_gstreamer_info (JNIEnv * env, jobject thiz)
{
    char *version_utf8 = gst_version_string ();
    jstring *version_jstring = (*env)->NewStringUTF (env, version_utf8);
    g_free (version_utf8);
    return version_jstring;
}

static JNINativeMethod native_methods[] = {
        {"nativeGetGStreamerInfo", "()Ljava/lang/String;",
                (void *) gst_native_get_gstreamer_info}
};

jint
JNI_OnLoad (JavaVM * vm, void *reserved)
{
    JNIEnv *env = NULL;

    if ((*vm)->GetEnv (vm, (void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        __android_log_print (ANDROID_LOG_ERROR, "tutorial-1",
                             "Could not retrieve JNIEnv");
        return 0;
    }
    jclass klass = (*env)->FindClass (env,
                                      "org/freedesktop/gstreamer/tutorials/tutorial_1/Tutorial1");
    (*env)->RegisterNatives (env, klass, native_methods,
                             G_N_ELEMENTS (native_methods));

    return JNI_VERSION_1_4;
}
#endif
