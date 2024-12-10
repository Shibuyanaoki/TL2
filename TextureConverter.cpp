#include "TextureConverter.h"
#include <Windows.h>

void TextureConverter::LoadWICTextureFromFIle(const std::string& filePath)
{
	// �t�@�C���p�X�����C��������ɕϊ�����
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	// WIC�e�N�X�`���̃��[�h
	HRESULT result = LoadFromWICFile(wfilePath.c_str(), DirectX::WIC_FLAGS::WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));

	SeparateFilePath(wfilePath);

}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	std::wstring wString;
	wString.resize(filePathBufferSize);

	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}

void TextureConverter::SeparateFilePath(const std::wstring& filePath)
{
	size_t pos1;
	std::wstring exceptExt;

	// ��؂蕶�� '.' ���o�Ă����ԍŌ�̕���������
	pos1 = filePath.rfind('.');

	// �������q�b�g������
	if (pos1 != std::wstring::npos) {
		// ��؂蕶���̌����t�@�C���g���q�Ƃ��ĕۑ�
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);

		// ��؂蕶���̑O�܂ł𔲂��o��
		exceptExt = filePath.substr(0, pos1);
	}
	else {
		fileExt_ = L"";

		exceptExt = filePath;
	}

	// ��؂����'\\'���o�Ă����ԍŌ�̕���������
	pos1 = exceptExt.rfind('\\');

	// �������q�b�g������
	if (pos1 != std::wstring::npos) {
		// ��؂蕶���̑O�܂ł��f�B���N�g���p�X�Ƃ��ĕۑ�
		directoryPath_ = exceptExt.substr(0, pos1 + 1);
		
		// ��؂蕶���̌����t�@�C�����Ƃ��ĕۑ�
		fileName_ = exceptExt.substr(pos1 + 1, filePath.size() - pos1 - 1);
		return;
	}

	// ��؂����'/'���o�Ă����ԍŌ�̕���������
	pos1 = exceptExt.rfind('/');

	// �������q�b�g������
	if (pos1 != std::wstring::npos) {
		// ��؂蕶���̑O�܂ł��f�B���N�g���p�X�Ƃ��ĕۑ�
		directoryPath_ = exceptExt.substr(0, pos1 + 1);

		// ��؂蕶���̌����t�@�C�����Ƃ��ĕۑ�
		fileName_ = exceptExt.substr(pos1 + 1, filePath.size() - pos1 - 1);
		return;
	}
	
	// ��؂蕶�����Ȃ��̂Ńt�@�C�����݂̂Ƃ��Ĉ���
	directoryPath_ = L"";
	fileName_ = exceptExt;

}

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{

	LoadWICTextureFromFIle(filePath);	

}
