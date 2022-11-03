# Herda as configurações do emulador (produto sdk_phone_x86_64)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_phone_x86_64.mk)

# Sobrescreve algumas variáveis com os dados do novo produto
PRODUCT_NAME := devtitans_xgate
PRODUCT_DEVICE := xgate
PRODUCT_BRAND := XGateBrand
PRODUCT_MODEL := XGateModel

PRODUCT_SYSTEM_PROPERTIES += \
    ro.devtitans.name=xgate

PRODUCT_PRODUCT_PROPERTIES += \
    ro.product.devtitans.version=1.0

PRODUCT_VENDOR_PROPERTIES += \
    ro.vendor.devtitans.hardware=ModelB

PRODUCT_COPY_FILES += \
    device/devtitans/xgate/bootanimation.zip:product/media/bootanimation.zip

# Seta o diretório de overlays
PRODUCT_PACKAGE_OVERLAYS = device/devtitans/xgate/overlay

PRODUCT_PACKAGES += \
    hello_c
