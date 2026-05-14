// Address: 0x140205de0
// Ghidra name: FUN_140205de0
// ============ 0x140205de0 FUN_140205de0 (size=146) ============


undefined8 FUN_140205de0(int *param_1,int *param_2,longlong *param_3,int *param_4)



{

  int iVar1;

  undefined8 uVar2;

  

  iVar1 = *param_1;

  if ((((iVar1 != 0x3132564e) && (iVar1 != 0x3231564e)) && (iVar1 != 0x32315659)) &&

     (iVar1 != 0x56555949)) {

    uVar2 = FUN_14012e850("Unsupported YUV format");

    return uVar2;

  }

  if (param_2 == (int *)0x0) {

    *param_3 = *(longlong *)(param_1 + 0xc);

    iVar1 = param_1[8];

    *param_4 = iVar1;

    return CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

  }

  if (((*param_2 == 0) && (param_2[1] == 0)) &&

     ((param_2[2] == param_1[3] && (param_2[3] == param_1[4])))) {

    *param_3 = (longlong)(param_2[1] * param_1[8]) + (longlong)(*param_2 * 2) +

               *(longlong *)(param_1 + 0xc);

    iVar1 = param_1[8];

    *param_4 = iVar1;

    return CONCAT71((uint7)(uint3)((uint)iVar1 >> 8),1);

  }

  uVar2 = FUN_14012e850("YV12, IYUV, NV12, NV21 textures only support full surface locks");

  return uVar2;

}




