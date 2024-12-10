#include "TextureConverter.h"
#include <Windows.h>

void TextureConverter::LoadWICTextureFromFIle(const std::string& filePath)
{
	// ファイルパスをワイル文字列に変換する
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);

	// WICテクスチャのロード
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

	// 区切り文字 '.' が出てくる一番最後の部分を検索
	pos1 = filePath.rfind('.');

	// 検索がヒットしたら
	if (pos1 != std::wstring::npos) {
		// 区切り文字の後ろをファイル拡張子として保存
		fileExt_ = filePath.substr(pos1 + 1, filePath.size() - pos1 - 1);

		// 区切り文字の前までを抜き出す
		exceptExt = filePath.substr(0, pos1);
	}
	else {
		fileExt_ = L"";

		exceptExt = filePath;
	}

	// 区切りもじ'\\'が出てくる一番最後の部分を検索
	pos1 = exceptExt.rfind('\\');

	// 検索がヒットしたら
	if (pos1 != std::wstring::npos) {
		// 区切り文字の前までをディレクトリパスとして保存
		directoryPath_ = exceptExt.substr(0, pos1 + 1);
		
		// 区切り文字の後ろをファイル名として保存
		fileName_ = exceptExt.substr(pos1 + 1, filePath.size() - pos1 - 1);
		return;
	}

	// 区切りもじ'/'が出てくる一番最後の部分を検索
	pos1 = exceptExt.rfind('/');

	// 検索がヒットしたら
	if (pos1 != std::wstring::npos) {
		// 区切り文字の前までをディレクトリパスとして保存
		directoryPath_ = exceptExt.substr(0, pos1 + 1);

		// 区切り文字の後ろをファイル名として保存
		fileName_ = exceptExt.substr(pos1 + 1, filePath.size() - pos1 - 1);
		return;
	}
	
	// 区切り文字がないのでファイル名のみとして扱う
	directoryPath_ = L"";
	fileName_ = exceptExt;

}

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{

	LoadWICTextureFromFIle(filePath);	

}
