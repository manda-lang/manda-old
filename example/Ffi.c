#include <manda.h>
#include <stdint.h>

void my_extension_init(manda_context_t*, ctx, manda_object_t* object) {
  manda_set_property(ctx, object, "isEven", manda_wrap_function(isEven));
}

manda_object_t* isEven(manda_context_t* ctx, manda_arguments_t* args) {
  int64_t x;
  manda_object_t* x_object = manda_get_argument(ctx, args, 0);
  
  if (manda_num_to_int64(ctx, x_object, &x) == 0) {
    return manda_bool(ctx, x % 2 == 0);
  } else {
    return manda_last_error(ctx);
  }
}

