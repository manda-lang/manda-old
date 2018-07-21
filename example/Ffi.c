#include <manda/manda.h>
#include <stdint.h>

manda_object_t* my_extension_init(manda_t* ctx) {
  manda_object_t* object = manda_new_object();
  manda_object_t* func = manda_wrap_function(ctx, isEven);
  manda_set_property(ctx, object, "isEven", func);
  return object;
}

manda_object_t* isEven(manda_t* ctx, manda_arguments_t arguments) {
  int64_t x;
  manda_object-t* xObject = arguments.values[0];
  
  if (manda_num_to_int64(ctx, xObject, &x) == 0) {
    return manda_new_bool(ctx, (x % 2 == 0);
  } else {
    return manda_get_last_error(ctx);
  }
}

