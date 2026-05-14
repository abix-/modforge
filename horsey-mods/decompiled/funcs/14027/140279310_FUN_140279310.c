// Address: 0x140279310
// Ghidra name: FUN_140279310
// ============ 0x140279310 FUN_140279310 (size=232) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_140279310(longlong param_1,undefined8 param_2,byte *param_3)



{

  float local_18;

  float local_14;

  float local_10;

  

  if (*(char *)(param_1 + 0x2b) != '\0') {

    local_18 = (float)((uint)((float)(int)((*param_3 >> 5 & 3 | (uint)param_3[2] << 2) - 0x200) /

                             DAT_14039ca5c) ^ DAT_14039cac0) * _DAT_1403553cc;

    local_14 = ((float)(int)((param_3[1] >> 5 & 2 | (uint)param_3[4] << 2) - 0x200) / DAT_14039ca5c)

               * _DAT_1403553cc;

    local_10 = ((float)(int)((param_3[1] >> 4 & 2 | (uint)param_3[3] << 2) - 0x200) / DAT_14039ca5c)

               * _DAT_1403553cc;

    FUN_14015afd0(*(undefined8 *)(param_1 + 0x10),param_2,1,*(undefined8 *)(param_1 + 0x10),

                  &local_18,3);

  }

  return;

}




