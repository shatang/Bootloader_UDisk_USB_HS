#include "usb_bsp.h"
#include "sys.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////
//USB-BSP ����
//////////////////////////////////////////////////////////////////////////////////


//USB OTG �ײ�IO��ʼ��
//pdev:USB OTG�ں˽ṹ��ָ��
void USB_OTG_BSP_Init(USB_OTG_CORE_HANDLE *pdev)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_OTG_HS, ENABLE);
    RCC_AHB1PeriphClockLPModeCmd(RCC_AHB1Periph_OTG_HS_ULPI, DISABLE);/* USB OTG HS ULPI clock Disabled */

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOB,GPIO_PinSource14,GPIO_AF_OTG_HS_FS);
    GPIO_PinAFConfig(GPIOB,GPIO_PinSource15,GPIO_AF_OTG_HS_FS);
}
//USB OTG �ж�����,����USB HS�ж�
//pdev:USB OTG�ں˽ṹ��ָ��
void USB_OTG_BSP_EnableInterrupt(USB_OTG_CORE_HANDLE *pdev)
{
    NVIC_InitTypeDef   NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = OTG_HS_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//��ռ���ȼ�0
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;//�����ȼ�3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//ʹ��ͨ��
    NVIC_Init(&NVIC_InitStructure);//����

}
//USB OTG �ж�����,����USB FS�ж�
//pdev:USB OTG�ں˽ṹ��ָ��
void USB_OTG_BSP_DisableInterrupt(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_OTG_HS, DISABLE);//++slj 15-9-28�ر�USB OTGʱ��
}
//USB OTG �˿ڹ�������(������δ�õ�)
//pdev:USB OTG�ں˽ṹ��ָ��
//state:0,�ϵ�;1,�ϵ�
void USB_OTG_BSP_DriveVBUS(USB_OTG_CORE_HANDLE *pdev, uint8_t state)
{
}
//USB_OTG �˿ڹ���IO����(������δ�õ�)
//pdev:USB OTG�ں˽ṹ��ָ��
void  USB_OTG_BSP_ConfigVBUS(USB_OTG_CORE_HANDLE *pdev)
{
}
//USB_OTG us����ʱ����
//�����̲���SYSTEM�ļ��е�delay.c�����delay_us����ʵ��
//�ٷ����̲��õ��Ƕ�ʱ��2��ʵ�ֵ�.
//usec:Ҫ��ʱ��us��.
void USB_OTG_BSP_uDelay (const uint32_t usec)
{
    delay_us(usec);
}
//USB_OTG ms����ʱ����
//�����̲���SYSTEM�ļ��е�delay.c�����delay_ms����ʵ��
//�ٷ����̲��õ��Ƕ�ʱ��2��ʵ�ֵ�.
//msec:Ҫ��ʱ��ms��.
void USB_OTG_BSP_mDelay (const uint32_t msec)
{
    delay_ms(msec);
}




