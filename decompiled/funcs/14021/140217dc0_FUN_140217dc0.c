// Address: 0x140217dc0
// Ghidra name: FUN_140217dc0
// ============ 0x140217dc0 FUN_140217dc0 (size=113) ============


ulonglong FUN_140217dc0(undefined8 param_1,undefined8 *param_2,undefined8 *param_3,

                       undefined8 *param_4,char *param_5)



{

  undefined8 *puVar1;

  char cVar2;

  ulonglong uVar3;

  undefined8 *puVar4;

  

  puVar4 = (undefined8 *)*param_2;

  *param_3 = *puVar4;

  *(undefined4 *)(param_3 + 1) = *(undefined4 *)(puVar4 + 1);

  uVar3 = 0;

  *param_4 = puVar4[2];

  while( true ) {

    puVar1 = (undefined8 *)puVar4[4];

    if (~uVar3 <= (ulonglong)(puVar4[9] - puVar4[8])) break;

    uVar3 = uVar3 + (puVar4[9] - puVar4[8]);

    cVar2 = *(char *)(puVar4 + 3);

    if (cVar2 != '\0') goto LAB_140217e23;

    puVar4 = puVar1;

    if (puVar1 == (undefined8 *)0x0) {

      *param_2 = 0;

      *param_5 = '\0';

      return uVar3;

    }

  }

  cVar2 = '\0';

  uVar3 = 0xffffffffffffffff;

LAB_140217e23:

  *param_2 = puVar1;

  *param_5 = cVar2;

  return uVar3;

}




