// Address: 0x1401bbe40
// Ghidra name: FUN_1401bbe40
// ============ 0x1401bbe40 FUN_1401bbe40 (size=94) ============


longlong FUN_1401bbe40(undefined8 param_1,undefined8 param_2,longlong *param_3,char param_4,

                      undefined4 param_5)



{

  int iVar1;

  

  if (param_4 != '\0') {

    iVar1 = FUN_140138fe0(*param_3 + 0x30);

    if (0 < iVar1) {

      FUN_1401b8640(param_1,param_3);

    }

  }

  FUN_1401b5050(param_1,param_2,param_5,*param_3);

  return *param_3;

}




