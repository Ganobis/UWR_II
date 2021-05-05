using System;
using System.IO;

namespace Zad2
{
    public class CaesarStream : Stream
    {
        private Stream _stream;
        private int _offset;
        public CaesarStream(Stream stream, int offset)
        {
            this._stream = stream;
            this._offset = offset;
        }
        public override bool CanRead => _stream.CanRead;

        public override bool CanSeek => _stream.CanSeek;

        public override bool CanWrite => _stream.CanSeek;

        public override long Length => _stream.Length;

        public override long Position { get => _stream.Position; set => _stream.Position = value; }

        public override void Flush()
        {
            _stream.Flush();
        }

        public override int Read(byte[] buffer, int offset, int count)
        {
            var result = this._stream.Read(buffer, offset, count);
            for (int i = 0; i < buffer.Length; i++)
            {
                buffer[i] = (byte)(((int)buffer[i] + this._offset) % 255);
            }
            return result;
        }

        public override long Seek(long offset, SeekOrigin origin)
        {
            return this._stream.Seek(offset, origin);
        }

        public override void SetLength(long value)
        {
            this._stream.SetLength(value);
        }

        public override void Write(byte[] buffer, int offset, int count)
        {
            var newBuffer = new byte[buffer.Length];
            for (int i = 0; i < buffer.Length; i++)
            {
                newBuffer[i] = (byte)(((int)buffer[i] + this._offset) % 255);
            }
            this._stream.Write(newBuffer, offset, count);
        }
    }
}
