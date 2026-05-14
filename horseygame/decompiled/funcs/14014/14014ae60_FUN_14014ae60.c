// Address: 0x14014ae60
// Ghidra name: FUN_14014ae60
// ============ 0x14014ae60 FUN_14014ae60 (size=237) ============


char FUN_14014ae60(longlong param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  char cVar6;

  undefined4 *puVar7;

  

  if ((((*(char *)(param_1 + 0x291) != '\0') && (*param_2 == *(float *)(param_1 + 0x25c))) &&

      (param_2[1] == *(float *)(param_1 + 0x260))) &&

     ((param_2[2] == *(float *)(param_1 + 0x264) && (param_2[3] == *(float *)(param_1 + 0x268))))) {

    return '\x01';

  }

  puVar7 = (undefined4 *)FUN_1401499f0();

  if (puVar7 == (undefined4 *)0x0) {

    return '\0';

  }

  *puVar7 = 3;

  *(undefined8 *)(puVar7 + 2) = 0;

  puVar7[4] = *(undefined4 *)(param_1 + 0x218);

  fVar1 = param_2[1];

  fVar2 = param_2[2];

  fVar3 = param_2[3];

  puVar7[5] = *param_2;

  puVar7[6] = fVar1;

  puVar7[7] = fVar2;

  puVar7[8] = fVar3;

  cVar6 = (**(code **)(param_1 + 0x28))(param_1,puVar7);

  if (cVar6 != '\0') {

    uVar4 = *(undefined8 *)param_2;

    uVar5 = *(undefined8 *)(param_2 + 2);

    *(undefined1 *)(param_1 + 0x291) = 1;

    *(undefined8 *)(param_1 + 0x25c) = uVar4;

    *(undefined8 *)(param_1 + 0x264) = uVar5;

    return cVar6;

  }

  *puVar7 = 0;

  return '\0';

}




