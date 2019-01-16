# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := cctest
DEFS_Debug := \
	'-DNODE_WANT_INTERNALS=1' \
	'-DHAVE_OPENSSL=1' \
	'-DHAVE_INSPECTOR=1' \
	'-D__POSIX__' \
	'-DNODE_USE_V8_PLATFORM=1' \
	'-DNODE_HAVE_I18N_SUPPORT=1' \
	'-DNODE_HAVE_SMALL_ICU=1' \
	'-DUCONFIG_NO_SERVICE=1' \
	'-DU_ENABLE_DYLOAD=0' \
	'-DU_STATIC_IMPLEMENTATION=1' \
	'-DU_HAVE_STD_STRING=1' \
	'-DUCONFIG_NO_BREAK_ITERATION=0' \
	'-DHTTP_PARSER_STRICT=0' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-D_POSIX_C_SOURCE=200112' \
	'-DNGHTTP2_STATICLIB' \
	'-DDEBUG' \
	'-D_DEBUG' \
	'-DV8_ENABLE_CHECKS'

# Flags passed to all source files.
CFLAGS_Debug := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++1y

INCS_Debug := \
	-I$(srcdir)/src \
	-I$(srcdir)/tools/msvs/genfiles \
	-I$(srcdir)/deps/v8/include \
	-I$(srcdir)/deps/cares/include \
	-I$(srcdir)/deps/uv/include \
	-I$(obj)/gen \
	-I$(srcdir)/deps/gtest/include \
	-I$(srcdir)/deps/v8/include \
	-I$(srcdir)/deps/icu-small/source/i18n \
	-I$(srcdir)/deps/icu-small/source/common \
	-I$(srcdir)/deps/zlib \
	-I$(srcdir)/deps/http_parser \
	-I$(srcdir)/deps/llhttp/include \
	-I$(srcdir)/deps/nghttp2/lib/includes \
	-I$(srcdir)/deps/openssl/openssl/include

DEFS_Release := \
	'-DNODE_WANT_INTERNALS=1' \
	'-DHAVE_OPENSSL=1' \
	'-DHAVE_INSPECTOR=1' \
	'-D__POSIX__' \
	'-DNODE_USE_V8_PLATFORM=1' \
	'-DNODE_HAVE_I18N_SUPPORT=1' \
	'-DNODE_HAVE_SMALL_ICU=1' \
	'-DUCONFIG_NO_SERVICE=1' \
	'-DU_ENABLE_DYLOAD=0' \
	'-DU_STATIC_IMPLEMENTATION=1' \
	'-DU_HAVE_STD_STRING=1' \
	'-DUCONFIG_NO_BREAK_ITERATION=0' \
	'-DHTTP_PARSER_STRICT=0' \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-D_POSIX_C_SOURCE=200112' \
	'-DNGHTTP2_STATICLIB'

# Flags passed to all source files.
CFLAGS_Release := \
	-pthread \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-m64 \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-O3 \
	-fno-omit-frame-pointer

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions \
	-std=gnu++1y

INCS_Release := \
	-I$(srcdir)/src \
	-I$(srcdir)/tools/msvs/genfiles \
	-I$(srcdir)/deps/v8/include \
	-I$(srcdir)/deps/cares/include \
	-I$(srcdir)/deps/uv/include \
	-I$(obj)/gen \
	-I$(srcdir)/deps/gtest/include \
	-I$(srcdir)/deps/v8/include \
	-I$(srcdir)/deps/icu-small/source/i18n \
	-I$(srcdir)/deps/icu-small/source/common \
	-I$(srcdir)/deps/zlib \
	-I$(srcdir)/deps/http_parser \
	-I$(srcdir)/deps/llhttp/include \
	-I$(srcdir)/deps/nghttp2/lib/includes \
	-I$(srcdir)/deps/openssl/openssl/include

OBJS := \
	$(obj).target/$(TARGET)/test/cctest/node_test_fixture.o \
	$(obj).target/$(TARGET)/test/cctest/test_aliased_buffer.o \
	$(obj).target/$(TARGET)/test/cctest/test_base64.o \
	$(obj).target/$(TARGET)/test/cctest/test_node_postmortem_metadata.o \
	$(obj).target/$(TARGET)/test/cctest/test_environment.o \
	$(obj).target/$(TARGET)/test/cctest/test_platform.o \
	$(obj).target/$(TARGET)/test/cctest/test_traced_value.o \
	$(obj).target/$(TARGET)/test/cctest/test_util.o \
	$(obj).target/$(TARGET)/test/cctest/test_url.o \
	$(obj).target/$(TARGET)/test/cctest/test_inspector_socket.o \
	$(obj).target/$(TARGET)/test/cctest/test_inspector_socket_server.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# Make sure our dependencies are built before any of us.
$(OBJS): | $(obj).target/libnode.a $(obj).target/rename_node_bin_win.stamp $(obj).target/deps/gtest/libgtest.a $(obj).target/node_dtrace_header.stamp $(obj).target/node_dtrace_ustack.stamp $(obj).target/node_dtrace_provider.stamp $(obj).target/deps/v8/gypfiles/v8.stamp $(obj).target/deps/v8/gypfiles/libv8_libplatform.a $(obj).target/tools/icu/libicui18n.a $(obj).target/tools/icu/icuuc.stamp $(obj).target/deps/zlib/libzlib.a $(obj).target/deps/http_parser/libhttp_parser.a $(obj).target/deps/llhttp/libllhttp.a $(obj).target/deps/cares/libcares.a $(obj).target/deps/uv/libuv.a $(obj).target/deps/nghttp2/libnghttp2.a $(obj).target/deps/openssl/libopenssl.a $(builddir)/openssl-cli $(obj).target/deps/v8/gypfiles/v8_maybe_snapshot.stamp $(obj).target/deps/v8/gypfiles/libv8_base.a $(obj).target/deps/v8/gypfiles/libv8_libbase.a $(obj).target/deps/v8/gypfiles/libv8_libsampler.a $(obj).host/deps/v8/gypfiles/v8_torque.stamp $(obj).target/deps/v8/gypfiles/postmortem-metadata.stamp $(obj).target/tools/icu/libicuucx.a $(obj).target/tools/icu/icu_implementation.stamp $(obj).target/tools/icu/icu_uconfig.stamp $(obj).target/tools/icu/icu_uconfig_target.stamp $(obj).target/tools/icu/libicudata.a $(obj).target/tools/icu/libicustubdata.a $(obj).target/deps/v8/gypfiles/libv8_snapshot.a $(obj).target/deps/v8/gypfiles/js2c.stamp

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m64 \
	-Wl,--whole-archive,$(builddir)/obj.target/deps/zlib/libzlib.a \
	-Wl,--no-whole-archive \
	-Wl,--whole-archive,$(builddir)/obj.target/deps/uv/libuv.a \
	-Wl,--no-whole-archive \
	-Wl,-z,noexecstack \
	-Wl,--whole-archive $(builddir)/obj.target/deps/v8/gypfiles/libv8_base.a \
	-Wl,--no-whole-archive \
	-Wl,-z,relro \
	-Wl,-z,now \
	-Wl,--whole-archive,$(builddir)/obj.target/deps/openssl/libopenssl.a \
	-Wl,--no-whole-archive \
	-pthread

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m64 \
	-Wl,--whole-archive,$(builddir)/obj.target/deps/zlib/libzlib.a \
	-Wl,--no-whole-archive \
	-Wl,--whole-archive,$(builddir)/obj.target/deps/uv/libuv.a \
	-Wl,--no-whole-archive \
	-Wl,-z,noexecstack \
	-Wl,--whole-archive $(builddir)/obj.target/deps/v8/gypfiles/libv8_base.a \
	-Wl,--no-whole-archive \
	-Wl,-z,relro \
	-Wl,-z,now \
	-Wl,--whole-archive,$(builddir)/obj.target/deps/openssl/libopenssl.a \
	-Wl,--no-whole-archive \
	-pthread

LIBS := \
	-ldl \
	-lrt \
	-lm

$(builddir)/cctest: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(builddir)/cctest: LIBS := $(LIBS)
$(builddir)/cctest: LD_INPUTS := $(OBJS) $(obj).target/libnode.a $(obj).target/deps/gtest/libgtest.a $(obj).target/deps/v8/gypfiles/libv8_libplatform.a $(obj).target/tools/icu/libicui18n.a $(obj).target/deps/zlib/libzlib.a $(obj).target/deps/http_parser/libhttp_parser.a $(obj).target/deps/llhttp/libllhttp.a $(obj).target/deps/cares/libcares.a $(obj).target/deps/uv/libuv.a $(obj).target/deps/nghttp2/libnghttp2.a $(obj).target/deps/openssl/libopenssl.a $(obj).target/deps/v8/gypfiles/libv8_base.a $(obj).target/deps/v8/gypfiles/libv8_libbase.a $(obj).target/deps/v8/gypfiles/libv8_libsampler.a $(obj).target/tools/icu/libicuucx.a $(obj).target/tools/icu/libicudata.a $(obj).target/tools/icu/libicustubdata.a $(obj).target/deps/v8/gypfiles/libv8_snapshot.a
$(builddir)/cctest: TOOLSET := $(TOOLSET)
$(builddir)/cctest: $(OBJS) $(obj).target/libnode.a $(obj).target/deps/gtest/libgtest.a $(obj).target/deps/v8/gypfiles/libv8_libplatform.a $(obj).target/tools/icu/libicui18n.a $(obj).target/deps/zlib/libzlib.a $(obj).target/deps/http_parser/libhttp_parser.a $(obj).target/deps/llhttp/libllhttp.a $(obj).target/deps/cares/libcares.a $(obj).target/deps/uv/libuv.a $(obj).target/deps/nghttp2/libnghttp2.a $(obj).target/deps/openssl/libopenssl.a $(obj).target/deps/v8/gypfiles/libv8_base.a $(obj).target/deps/v8/gypfiles/libv8_libbase.a $(obj).target/deps/v8/gypfiles/libv8_libsampler.a $(obj).target/tools/icu/libicuucx.a $(obj).target/tools/icu/libicudata.a $(obj).target/tools/icu/libicustubdata.a $(obj).target/deps/v8/gypfiles/libv8_snapshot.a FORCE_DO_CMD
	$(call do_cmd,link)

all_deps += $(builddir)/cctest
# Add target alias
.PHONY: cctest
cctest: $(builddir)/cctest

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/cctest

