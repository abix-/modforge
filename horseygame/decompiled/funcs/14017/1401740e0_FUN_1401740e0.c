// Address: 0x1401740e0
// Ghidra name: FUN_1401740e0
// ============ 0x1401740e0 FUN_1401740e0 (size=68) ============


undefined8 FUN_1401740e0(void)



{

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (*(int *)(DAT_1403fc410 + 0x570) == 0) {

    FUN_14012e850("No Vulkan loader has been loaded");

    return 0;

  }

  return *(undefined8 *)(DAT_1403fc410 + 0x560);

}




