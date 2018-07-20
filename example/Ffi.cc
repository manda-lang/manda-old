#include <manda.h>
#include <cstdint.h>

void my_extension_init(MandaContext* ctx, MandaObject* object) {
  ctx->setProperty(object, "isEven", ctx->wrapFunction(isEven));
}

MandaObject* isEven(MandaContext* ctx, MandaArguments* arguments) {
  int64_t x;
  MandaObject* xObject = ctx->getArgument(arguments, 0);
  
  if (ctx->numToInt64(xObject, &x) == 0) {
    return ctx->newBool(x % 2 == 0);
  } else {
    return ctx->getLastError(ctx);
  }
}

