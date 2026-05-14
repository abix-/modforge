// Address: 0x1401e7e70
// Ghidra name: FUN_1401e7e70
// ============ 0x1401e7e70 FUN_1401e7e70 (size=69) ============


undefined8 FUN_1401e7e70(longlong param_1)



{

  undefined8 *puVar1;

  undefined8 uVar2;

  

  puVar1 = *(undefined8 **)(*(longlong *)(param_1 + 0x2e0) + 0x2260);

  if (puVar1 != (undefined8 *)0x0) {

    uVar2 = *puVar1;

    *(undefined8 *)(*(longlong *)(param_1 + 0x2e0) + 0x2260) = puVar1[1];

    return uVar2;

  }

  FUN_14012e850("[d3d12] Cannot allocate more than %d textures!",0x4000);

  return 0x4001;

}




